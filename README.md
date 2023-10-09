# c-raytracer
A raytracer in C

```
sudo apt install linux-tools-common linux-tools-generic linux-tools-6.2.0-32-generic
sudo apt install hotspot
```


perf gets you the instruction to get access

sudo sh -c "echo -1 > /proc/sys/kernel/perf_event_paranoid"
sudo sh -c "echo 0 > /proc/sys/kernel/kptr_restrict"
/etc/sysctl.conf
kernel.perf_event_paranoid=-1


```
clang main.c -g -lm -o rt_clang
gcc main.c -g -lm -o rt_gcc
```
