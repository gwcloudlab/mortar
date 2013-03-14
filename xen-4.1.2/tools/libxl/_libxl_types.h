#ifndef __LIBXL_TYPES_H
#define __LIBXL_TYPES_H

/*
 * DO NOT EDIT.
 *
 * This file is autogenerated by
 * "gentypes.py libxl.idl __libxl_types.h __libxl_types.c"
 */
 
typedef struct {
    libxl_uuid uuid;
    uint32_t domid;
    uint8_t running:1;
    uint8_t blocked:1;
    uint8_t paused:1;
    uint8_t shutdown:1;
    uint8_t dying:1;
    /*
     * Valid SHUTDOWN_* value from xen/sched.h iff (shutdown||dying).
     *
     * Otherwise set to a value guaranteed not to clash with any valid
     * SHUTDOWN_* constant.
     */
    unsigned int shutdown_reason;
    uint64_t current_memkb;
    uint64_t max_memkb;
    uint64_t cpu_time;
    uint32_t vcpu_max_id;
    uint32_t vcpu_online;
} libxl_dominfo;

typedef struct {
    uint32_t poolid;
    uint32_t sched_id;
    uint32_t n_dom;
    libxl_cpumap cpumap;
} libxl_cpupoolinfo;
void libxl_cpupoolinfo_destroy(libxl_cpupoolinfo *p);

typedef struct {
    libxl_uuid uuid;
    uint32_t domid;
} libxl_vminfo;

typedef struct {
    int xen_version_major;
    int xen_version_minor;
    char * xen_version_extra;
    char * compiler;
    char * compile_by;
    char * compile_domain;
    char * compile_date;
    char * capabilities;
    char * changeset;
    unsigned long virt_start;
    unsigned long pagesize;
    char * commandline;
} libxl_version_info;
void libxl_version_info_destroy(libxl_version_info *p);

typedef struct {
    bool hvm;
    bool hap;
    bool oos;
    int ssidref;
    char * name;
    libxl_uuid uuid;
    libxl_key_value_list xsdata;
    libxl_key_value_list platformdata;
    uint32_t poolid;
    char * poolname;
} libxl_domain_create_info;
void libxl_domain_create_info_destroy(libxl_domain_create_info *p);

/*
 * Instances of libxl_file_reference contained in this struct which
 * have been mapped (with libxl_file_reference_map) will be unmapped
 * by libxl_domain_build/restore. If either of these are never called
 * then the user is responsible for calling
 * libxl_file_reference_unmap.
 */
typedef struct {
    int max_vcpus;
    int cur_vcpus;
    int tsc_mode;
    uint32_t max_memkb;
    uint32_t target_memkb;
    uint32_t video_memkb;
    uint32_t shadow_memkb;
    bool disable_migrate;
    libxl_file_reference kernel;
    libxl_cpuid_policy_list cpuid;
    int hvm;
    union {
        struct {
            bool pae;
            bool apic;
            bool acpi;
            bool nx;
            bool viridian;
            char * timeoffset;
            bool hpet;
            bool vpt_align;
            int timer_mode;
        } hvm;
        struct {
            uint32_t slack_memkb;
            char * bootloader;
            char * bootloader_args;
            char * cmdline;
            libxl_file_reference ramdisk;
            const char * features;
        } pv;
    } u;
} libxl_domain_build_info;
void libxl_domain_build_info_destroy(libxl_domain_build_info *p);

typedef struct {
    uint32_t store_port;
    unsigned long store_mfn;
    uint32_t console_port;
    unsigned long console_mfn;
} libxl_domain_build_state;

/*
 * Device Model information.
 *
 * Network is missing
 */
typedef struct {
    int domid;
    /*
     * this is use only with stubdom, and must be different from the domain uuid
     */
    libxl_uuid uuid;
    char * dom_name;
    char * device_model;
    char * saved_state;
    libxl_qemu_machine_type type;
    uint32_t target_ram;
    /*
     * size of the videoram in MB
     */
    int videoram;
    /*
     * stdvga enabled or disabled
     */
    bool stdvga;
    /*
     * vnc enabled or disabled
     */
    bool vnc;
    /*
     * address:port that should be listened on for the VNC server if vnc is set
     */
    char * vnclisten;
    /*
     * the VNC password
     */
    char * vncpasswd;
    /*
     * set VNC display number
     */
    int vncdisplay;
    /*
     * try to find an unused port for the VNC server
     */
    bool vncunused;
    /*
     * set keyboard layout, default is en-us keyboard
     */
    char * keymap;
    /*
     * sdl enabled or disabled
     */
    bool sdl;
    /*
     * opengl enabled or disabled (if enabled requires sdl enabled)
     */
    bool opengl;
    /*
     * no graphics, use serial port
     */
    bool nographic;
    /*
     * graphics passthrough enabled or disabled
     */
    bool gfx_passthru;
    /*
     * serial port re-direct to pty deivce
     */
    char * serial;
    /*
     * boot order, for example dca
     */
    char * boot;
    /*
     * usb support enabled or disabled
     */
    bool usb;
    /*
     * enable usb mouse: tablet for absolute mouse, mouse for PS/2 protocol relative mouse
     */
    char * usbdevice;
    /*
     * enable sound hardware
     */
    char * soundhw;
    /*
     * apic enabled or disabled
     */
    bool apic;
    /*
     * max number of vcpus
     */
    int vcpus;
    /*
     * vcpus actually available
     */
    int vcpu_avail;
    /*
     * enable/disable the xen platform pci device
     */
    int xen_platform_pci;
    /*
     * extra parameters pass directly to qemu, NULL terminated
     */
    libxl_string_list extra;
} libxl_device_model_info;
void libxl_device_model_info_destroy(libxl_device_model_info *p);

typedef struct {
    uint32_t backend_domid;
    uint32_t domid;
    int devid;
    /*
     * vnc enabled or disabled
     */
    bool vnc;
    /*
     * address:port that should be listened on for the VNC server if vnc is set
     */
    char * vnclisten;
    /*
     * the VNC password
     */
    char * vncpasswd;
    /*
     * set VNC display number
     */
    int vncdisplay;
    /*
     * try to find an unused port for the VNC server
     */
    bool vncunused;
    /*
     * set keyboard layout, default is en-us keyboard
     */
    char * keymap;
    /*
     * sdl enabled or disabled
     */
    bool sdl;
    /*
     * opengl enabled or disabled (if enabled requires sdl enabled)
     */
    bool opengl;
    char * display;
    char * xauthority;
} libxl_device_vfb;
void libxl_device_vfb_destroy(libxl_device_vfb *p);

typedef struct {
    uint32_t backend_domid;
    uint32_t domid;
    int devid;
} libxl_device_vkb;
void libxl_device_vkb_destroy(libxl_device_vkb *p);

typedef struct {
    uint32_t backend_domid;
    uint32_t domid;
    int devid;
    libxl_console_consback consback;
    const libxl_domain_build_state * build_state;
    char * output;
} libxl_device_console;
void libxl_device_console_destroy(libxl_device_console *p);

typedef struct {
    uint32_t backend_domid;
    uint32_t domid;
    char * pdev_path;
    char * vdev;
    libxl_disk_backend backend;
    libxl_disk_format format;
    int unpluggable;
    int readwrite;
    int is_cdrom;
} libxl_device_disk;
void libxl_device_disk_destroy(libxl_device_disk *p);

typedef struct {
    uint32_t backend_domid;
    uint32_t domid;
    int devid;
    int mtu;
    char * model;
    libxl_mac mac;
    char * ip;
    char * bridge;
    char * ifname;
    char * script;
    libxl_nic_type nictype;
} libxl_device_nic;
void libxl_device_nic_destroy(libxl_device_nic *p);

typedef struct {
    int devid;
    libxl_mac front_mac;
    libxl_mac back_mac;
    uint32_t backend_domid;
    uint32_t domid;
    uint32_t trusted:1;
    uint32_t back_trusted:1;
    uint32_t filter_mac:1;
    uint32_t front_filter_mac:1;
    uint32_t pdev;
    uint32_t max_bypasses;
    char * bridge;
} libxl_device_net2;
void libxl_device_net2_destroy(libxl_device_net2 *p);

typedef struct {
    uint8_t reg;
    uint8_t func;
    uint8_t dev;
    uint8_t bus;
    bool enable;
    unsigned int domain;
    unsigned int vdevfn;
    unsigned int vfunc_mask;
    bool msitranslate;
    bool power_mgmt;
} libxl_device_pci;
void libxl_device_pci_destroy(libxl_device_pci *p);

typedef struct {
    char * backend;
    uint32_t backend_id;
    char * frontend;
    uint32_t frontend_id;
    int devid;
    int state;
    int evtch;
    int rref;
} libxl_diskinfo;
void libxl_diskinfo_destroy(libxl_diskinfo *p);

typedef struct {
    char * backend;
    uint32_t backend_id;
    char * frontend;
    uint32_t frontend_id;
    int devid;
    int state;
    char * script;
    libxl_mac mac;
    int evtch;
    int rref_tx;
    int rref_rx;
} libxl_nicinfo;
void libxl_nicinfo_destroy(libxl_nicinfo *p);

typedef struct {
    /*
     * vcpu's id
     */
    uint32_t vcpuid;
    /*
     * current mapping
     */
    uint32_t cpu;
    /*
     * currently online (not hotplugged)?
     */
    uint8_t online:1;
    /*
     * blocked waiting for an event?
     */
    uint8_t blocked:1;
    /*
     * currently scheduled on its CPU?
     */
    uint8_t running:1;
    /*
     * total vcpu time ran (ns)
     */
    uint64_t vcpu_time;
    /*
     * current cpu's affinities
     */
    libxl_cpumap cpumap;
} libxl_vcpuinfo;
void libxl_vcpuinfo_destroy(libxl_vcpuinfo *p);

typedef struct {
    uint32_t threads_per_core;
    uint32_t cores_per_socket;
    uint32_t max_cpu_id;
    uint32_t nr_cpus;
    uint32_t cpu_khz;
    uint64_t total_pages;
    uint64_t free_pages;
    uint64_t scrub_pages;
    uint32_t nr_nodes;
    libxl_hwcap hw_cap;
    uint32_t phys_cap;
} libxl_physinfo;

typedef struct {
    /*
     * cpu to core map
     */
    libxl_cpuarray coremap;
    /*
     * cpu to socket map
     */
    libxl_cpuarray socketmap;
    /*
     * cpu to node map
     */
    libxl_cpuarray nodemap;
} libxl_topologyinfo;
void libxl_topologyinfo_destroy(libxl_topologyinfo *p);

typedef struct {
    int weight;
    int cap;
} libxl_sched_credit;

typedef struct {
    char * backend;
    uint32_t backend_id;
    char * frontend;
    uint32_t frontend_id;
    int devid;
    int state;
    libxl_mac mac;
    int trusted;
    libxl_mac back_mac;
    int filter_mac;
} libxl_net2info;
void libxl_net2info_destroy(libxl_net2info *p);

#endif /* __LIBXL_TYPES_H */
