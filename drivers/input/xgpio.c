#include <linux/list.h>
#include <linux/kernel.h>
#include <linux/clk.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_gpio.h>
#include <linux/gpio.h>
#include <linux/platform_device.h>
#include <linux/time.h>
#include <linux/delay.h>
#include <linux/interrupt.h>
#include <linux/slab.h>
#include <linux/kobject.h>
#include <linux/sysfs.h>
#include <linux/kthread.h>
#include <dt-bindings/gpio/gpio.h>

struct xgpio_device_t {
	int gpio;
	int state;
	struct device * dev;
};
int gpio_4g_reset,gpio_4g_poweren,gpio_4g_power_key;
static ssize_t xgpio_state_show(struct device * dev, struct device_attribute * attr, char * buf)
{
	struct xgpio_device_t * xdev = dev_get_drvdata(dev);

	if(!strcmp(attr->attr.name, "state"))
	{
		if(xdev->state == 0)
			return strlcpy(buf, "0\n", 3);
		else
			return strlcpy(buf, "1\n", 3);
	}
	return strlcpy(buf, "0\n", 3);
}

static ssize_t xgpio_state_store(struct device * dev, struct device_attribute * attr, const char * buf, size_t count)
{
	struct xgpio_device_t * xdev = dev_get_drvdata(dev);
	unsigned long on = simple_strtoul(buf, NULL, 10);

	if(!strcmp(attr->attr.name, "state"))
	{
		if(on){
			gpio_direction_output(xdev->gpio, 1);
			xdev->state = 1;
		}
		else{
			gpio_direction_output(xdev->gpio, 0);
			xdev->state = 0;
		}
	}
	return count;
}

static DEVICE_ATTR(state, 0664, xgpio_state_show, xgpio_state_store);
static struct attribute * xgpio_attrs[] = {
	&dev_attr_state.attr,
	NULL
};

static const struct attribute_group xgpio_group = {
	.attrs = xgpio_attrs,
};

static int xgpio_probe(struct platform_device * pdev)
{
	struct device_node * node = pdev->dev.of_node;
	struct xgpio_device_t * xdev;
	enum of_gpio_flags flags;
	int gpio;

	int val = 0;

	if(!node)
		return -ENODEV;
	
	gpio = of_get_named_gpio_flags(node, "gpio", 0, &flags);
	if(!gpio_is_valid(gpio))
	{
		printk("xgpio: invalid gpio %d\n", gpio);
		return -EINVAL;
	}
	
	if(devm_gpio_request(&pdev->dev, gpio, "xgpio-pin") != 0)
	{
		printk("xgpio: can not request gpio %d\n", gpio);
		return -EINVAL;
	}

	if(!of_property_read_u32(node, "def_val", &val)){
		if(val)
			gpio_direction_output(gpio, 1);
		else
			gpio_direction_output(gpio, 0);	
	}else
		gpio_direction_output(gpio, 0);

    if(!of_property_read_u32(node, "delayms", &val)){
        printk("xgpio:  gpio %d delay %d ms\n", gpio,val);
        mdelay(val);
    }


    gpio_4g_reset = of_get_named_gpio_flags(node, "gpio-4g-reset", 0, &flags);
    if(!gpio_is_valid(gpio_4g_reset))//4a7
    {
            printk("xgpio: invalid gpio %d\n", gpio_4g_reset);
            //return -EINVAL;
    }
    else if(devm_gpio_request(&pdev->dev, gpio_4g_reset, "gpio-4g-reset") != 0)
    {
            printk("xgpio: can not request gpio %d\n", gpio_4g_reset);
            //return -EINVAL;
    }
/*
    gpio_4g_poweren = of_get_named_gpio_flags(node, "gpio-4g-poweren", 0, &flags);
    if(!gpio_is_valid(gpio))
    {
            printk("xgpio: invalid gpio %d\n", gpio_4g_poweren);
            //return -EINVAL;
    }
    else if(devm_gpio_request(&pdev->dev, gpio_4g_poweren, "gpio-4g-poweren") != 0)
    {
            printk("xgpio: can not request gpio %d\n", gpio_4g_poweren);
            //return -EINVAL;
    }
*/
    gpio_4g_power_key = of_get_named_gpio_flags(node, "gpio-4g-power-key", 0, &flags);
    if(!gpio_is_valid(gpio_4g_power_key))//4B5
    {
            printk("xgpio: invalid gpio %d\n", gpio_4g_power_key);
            //return -EINVAL;
    }
    else if(devm_gpio_request(&pdev->dev, gpio_4g_power_key, "gpio-4g-power-key") != 0)
    {
            printk("xgpio: can not request gpio %d\n", gpio_4g_power_key);
            //return -EINVAL;
    }
    if(gpio_is_valid(gpio_4g_power_key))
    {// set power key low for 1 second
        printk("%s  4g power on \n", __func__);
        gpio_direction_output(gpio_4g_power_key, 1);
        gpio_direction_output(gpio, 0);
        mdelay(1000);
        gpio_direction_output(gpio_4g_power_key, 0);
        mdelay(2500);
        gpio_direction_output(gpio_4g_power_key, 1);
        //mdelay(400);
        //gpio_direction_output(gpio_4g_power_key, 0);
    }

    if(gpio_is_valid(gpio_4g_reset))
    {//reset  700ms-100
        printk("%s  4g reset \n", __func__);
        gpio_direction_output(gpio_4g_reset, 0);
        mdelay(800);
        gpio_direction_output(gpio_4g_reset, 1);
        mdelay(100);
        //gpio_direction_output(gpio_4g_reset, 0);
    }


	xdev = devm_kzalloc(&pdev->dev, sizeof(struct xgpio_device_t), GFP_KERNEL);
	if(!xdev)
		return -ENOMEM;

	xdev->gpio = gpio;
	if(val)
		xdev->state = 1;
	else
		xdev->state = 0;
	xdev->dev = &pdev->dev;
	dev_set_drvdata(&pdev->dev, xdev);

	return sysfs_create_group(&pdev->dev.kobj, &xgpio_group);
}

static int xgpio_remove(struct platform_device *pdev)
{
	struct xgpio_device_t * xdev = dev_get_drvdata(&pdev->dev);

	devm_gpio_free(&pdev->dev, xdev->gpio);
	sysfs_remove_group(&pdev->dev.kobj, &xgpio_group);
	return 0;
}

#ifdef CONFIG_PM
static int xgpio_suspend(struct device *dev)
{
	return 0;
}

static int xgpio_resume(struct device *dev)
{
	return 0;
}
#else
#define xgpio_suspend NULL
#define xgpio_resume NULL
#endif

static const struct dev_pm_ops xgpio_pm_ops = {
	.suspend = xgpio_suspend,
	.resume = xgpio_resume,
};

static struct of_device_id xgpio_of_match[] = {
	{ .compatible = "lylx,xgpio" },
	{},
};
MODULE_DEVICE_TABLE(of, xgpio_of_match);

static struct platform_driver xgpio_driver = {
	.driver		= {
		.name	= "xgpio",
		.owner	= THIS_MODULE,
		.pm	= &xgpio_pm_ops,
		.of_match_table	= of_match_ptr(xgpio_of_match),
	},
	.probe		= xgpio_probe,
	.remove		= xgpio_remove,
};
module_platform_driver(xgpio_driver);

MODULE_DESCRIPTION("xgpio driver");
MODULE_AUTHOR("wangwenjing, 443238132@qq.com");
MODULE_LICENSE("GPL");
