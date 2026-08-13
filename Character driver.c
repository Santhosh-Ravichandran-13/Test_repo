#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/string.h>

#define DEVICE_NAME "mychardev"
#define BUFFER_SIZE 1024

static int major;
static char kernel_buffer[BUFFER_SIZE];

static int device_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device Opened\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device Closed\n");
    return 0;
}

static ssize_t device_read(struct file *file,
                           char __user *buffer,
                           size_t length,
                           loff_t *offset)
{
    size_t bytes;

    bytes = strlen(kernel_buffer);

    if (*offset >= bytes)
        return 0;

    if (length > bytes - *offset)
        length = bytes - *offset;

    if (copy_to_user(buffer,
                     kernel_buffer + *offset,
                     length))
        return -EFAULT;

    *offset += length;

    printk(KERN_INFO "Data Read\n");

    return length;
}

static ssize_t device_write(struct file *file,
                            const char __user *buffer,
                            size_t length,
                            loff_t *offset)
{
    if (length >= BUFFER_SIZE)
        length = BUFFER_SIZE - 1;

    if (copy_from_user(kernel_buffer,
                       buffer,
                       length))
        return -EFAULT;

    kernel_buffer[length] = '\0';

    printk(KERN_INFO "Data Written: %s\n",
           kernel_buffer);

    return length;
}

static struct file_operations fops =
{
    .owner = THIS_MODULE,
    .open = device_open,
    .read = device_read,
    .write = device_write,
    .release = device_release
};

static int __init mydriver_init(void)
{
    major = register_chrdev(0, DEVICE_NAME, &fops);

    if (major < 0)
    {
        printk(KERN_ALERT "Registration Failed\n");
        return major;
    }

    printk(KERN_INFO "Driver Loaded\n");
    printk(KERN_INFO "Major Number = %d\n", major);

    return 0;
}

static void __exit mydriver_exit(void)
{
    unregister_chrdev(major, DEVICE_NAME);

    printk(KERN_INFO "Driver Removed\n");
}

module_init(mydriver_init);
module_exit(mydriver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Santhosh");
MODULE_DESCRIPTION("Simple Character Device Driver");
