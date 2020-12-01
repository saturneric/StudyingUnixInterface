# StudyingUnixInterface
对Linux/UNIX环境下的系统调用与公共函数库的学习实践代码
## 简介
本仓库中包含有本人在Linux/UNIX环境相关的笔记与代码，使用C语言并使用VIM编辑器进行编写。
## 运行环境
本仓库的代码均在本人的开发服务器上运行与调试
### 开发服务器环境
主要列出开发服务器的基本信息和软硬件环境
#### 系统基本信息
  1. Linux Saturneric-Dev 4.19.0-12-amd64 #1 SMP Debian 4.19.152-1 (2020-10-18) x86_64 GNU/Linux
  2. Debian GNU/Linux 10 \n \l
### 软件环境
1. 编译环境GCC
```
  Using built-in specs.
  COLLECT_GCC=gcc
  COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/8/lto-wrapper
  OFFLOAD_TARGET_NAMES=nvptx-none
  OFFLOAD_TARGET_DEFAULT=1
  Target: x86_64-linux-gnu
  Configured with: ../src/configure -v --with-pkgversion='Debian 8.3.0-6' --with-bugurl=file:///usr/share/doc/gcc-8/README.Bugs --enable-languages=c,ada,c++,go,brig,d,fortran,objc,obj-c++ --prefix=/usr --with-gcc-major-version-only --program-suffix=-8 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-bootstrap --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-libmpx --enable-plugin --enable-default-pie --with-system-zlib --with-target-system-zlib --enable-objc-gc=auto --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
  Thread model: posix
  gcc version 8.3.0 (Debian 8.3.0-6) 
```
2. 已加载的内核模块
```
    Module                  Size  Used by
  ipt_MASQUERADE         16384  1
  nf_conntrack_netlink    49152  0
  xfrm_user              40960  1
  xfrm_algo              16384  1 xfrm_user
  nft_chain_nat_ipv4     16384  4
  nf_nat_ipv4            16384  2 ipt_MASQUERADE,nft_chain_nat_ipv4
  br_netfilter           24576  0
  bridge                188416  1 br_netfilter
  stp                    16384  1 bridge
  llc                    16384  2 bridge,stp
  aufs                  274432  0
  rfkill                 28672  1
  overlay               131072  0
  binfmt_misc            20480  1
  snd_hda_codec_analog    20480  1
  snd_hda_codec_generic    86016  1 snd_hda_codec_analog
  snd_hda_intel          49152  1
  snd_hda_codec         151552  3 snd_hda_codec_generic,snd_hda_intel,snd_hda_codec_analog
  coretemp               16384  0
  snd_hda_core           94208  4 snd_hda_codec_generic,snd_hda_intel,snd_hda_codec_analog,snd_hda_codec
  snd_hwdep              16384  1 snd_hda_codec
  snd_pcm               114688  3 snd_hda_intel,snd_hda_codec,snd_hda_core
  snd_timer              36864  1 snd_pcm
  snd                    94208  9 snd_hda_codec_generic,snd_hwdep,snd_hda_intel,snd_hda_codec_analog,snd_hda_codec,snd_timer,snd_pcm
  kvm                   757760  0
  iTCO_wdt               16384  0
  iTCO_vendor_support    16384  1 iTCO_wdt
  soundcore              16384  1 snd
  irqbypass              16384  1 kvm
  dcdbas                 16384  0
  sg                     36864  0
  serio_raw              16384  0
  rng_core               16384  0
  evdev                  28672  2
  pcspkr                 16384  0
  nf_log_ipv6            16384  5
  ip6t_REJECT            16384  1
  nf_reject_ipv6         16384  1 ip6t_REJECT
  xt_hl                  16384  22
  ip6_tables             32768  52
  ip6t_rt                16384  3
  nf_log_ipv4            16384  5
  nf_log_common          16384  2 nf_log_ipv4,nf_log_ipv6
  ipt_REJECT             16384  1
  nf_reject_ipv4         16384  1 ipt_REJECT
  xt_LOG                 16384  10
  nft_limit              16384  13
  xt_limit               16384  0
  xt_addrtype            16384  6
  xt_tcpudp              16384  30
  xt_conntrack           16384  17
  nft_compat             20480  151
  nft_counter            16384  197
  nf_conntrack_netbios_ns    16384  0
  nf_conntrack_broadcast    16384  1 nf_conntrack_netbios_ns
  nf_nat_ftp             16384  0
  nf_nat                 36864  2 nf_nat_ftp,nf_nat_ipv4
  nf_conntrack_ftp       20480  1 nf_nat_ftp
  nf_conntrack          172032  9 xt_conntrack,nf_nat,nf_nat_ftp,ipt_MASQUERADE,nf_conntrack_netbios_ns,nf_nat_ipv4,nf_conntrack_broadcast,nf_conntrack_netlink,nf_conntrack_ftp
  nf_defrag_ipv6         20480  1 nf_conntrack
  nf_defrag_ipv4         16384  1 nf_conntrack
  libcrc32c              16384  2 nf_conntrack,nf_nat
  nf_tables             143360  472 nft_compat,nft_chain_nat_ipv4,nft_counter,nft_limit
  nfnetlink              16384  4 nft_compat,nf_conntrack_netlink,nf_tables
  parport_pc             32768  1
  ppdev                  20480  0
  lp                     20480  0
  parport                57344  3 parport_pc,lp,ppdev
  ip_tables              28672  8
  x_tables               45056  13 xt_conntrack,nft_compat,xt_LOG,xt_tcpudp,ipt_MASQUERADE,xt_addrtype,ip6t_rt,ip6_tables,ipt_REJECT,ip_tables,xt_limit,xt_hl,ip6t_REJECT
  autofs4                49152  2
  ext4                  745472  3
  crc16                  16384  1 ext4
  mbcache                16384  1 ext4
  jbd2                  122880  1 ext4
  crc32c_generic         16384  7
  fscrypto               32768  1 ext4
  ecb                    16384  0
  crypto_simd            16384  0
  cryptd                 28672  1 crypto_simd
  glue_helper            16384  0
  aes_x86_64             20480  0
  sd_mod                 61440  5
  ata_generic            16384  0
  ahci                   40960  4
  libahci                40960  1 ahci
  ata_piix               36864  0
  libata                270336  4 ata_piix,libahci,ahci,ata_generic
  i915                 1736704  1
  uhci_hcd               49152  0
  ehci_pci               16384  0
  ehci_hcd               94208  1 ehci_pci
  tg3                   188416  0
  psmouse               172032  0
  i2c_i801               28672  0
  video                  49152  1 i915
  scsi_mod              249856  3 sd_mod,libata,sg
  i2c_algo_bit           16384  1 i915
  drm_kms_helper        208896  1 i915
  lpc_ich                28672  0
  mfd_core               16384  1 lpc_ich
  usbcore               294912  3 ehci_pci,ehci_hcd,uhci_hcd
  drm                   495616  3 drm_kms_helper,i915
  usb_common             16384  1 usbcore
  libphy                 77824  1 tg3
  button                 16384  0
```
### 硬件环境
1. CPU
```
  processor	: 0
  vendor_id	: GenuineIntel
  cpu family	: 6
  model		: 23
  model name	: Intel(R) Core(TM)2 Duo CPU     E8400  @ 3.00GHz
  stepping	: 6
  microcode	: 0x60f
  cpu MHz		: 2014.515
  cache size	: 6144 KB
  physical id	: 0
  siblings	: 2
  core id		: 0
  cpu cores	: 2
  apicid		: 0
  initial apicid	: 0
  fpu		: yes
  fpu_exception	: yes
  cpuid level	: 10
  wp		: yes
  flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx lm constant_tsc arch_perfmon pebs bts rep_good nopl cpuid aperfmperf pni dtes64 monitor ds_cpl vmx smx est tm2 ssse3 cx16 xtpr pdcm sse4_1 lahf_lm pti tpr_shadow vnmi flexpriority dtherm
  bugs		: cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass l1tf mds swapgs itlb_multihit
  bogomips	: 5984.92
  clflush size	: 64
  cache_alignment	: 64
  address sizes	: 36 bits physical, 48 bits virtual
  power management:

  processor	: 1
  vendor_id	: GenuineIntel
  cpu family	: 6
  model		: 23
  model name	: Intel(R) Core(TM)2 Duo CPU     E8400  @ 3.00GHz
  stepping	: 6
  microcode	: 0x60f
  cpu MHz		: 2031.014
  cache size	: 6144 KB
  physical id	: 0
  siblings	: 2
  core id		: 1
  cpu cores	: 2
  apicid		: 1
  initial apicid	: 1
  fpu		: yes
  fpu_exception	: yes
  cpuid level	: 10
  wp		: yes
  flags		: fpu vme de pse tsc msr pae mce cx8 apic sep mtrr pge mca cmov pat pse36 clflush dts acpi mmx fxsr sse sse2 ss ht tm pbe syscall nx lm constant_tsc arch_perfmon pebs bts rep_good nopl cpuid aperfmperf pni dtes64 monitor ds_cpl vmx smx est tm2 ssse3 cx16 xtpr pdcm sse4_1 lahf_lm pti tpr_shadow vnmi flexpriority dtherm
  bugs		: cpu_meltdown spectre_v1 spectre_v2 spec_store_bypass l1tf mds swapgs itlb_multihit
  bogomips	: 5984.92
  clflush size	: 64
  cache_alignment	: 64
  address sizes	: 36 bits physical, 48 bits virtual
  power management:
```  
2. 内存信息
```
                total        used        free      shared  buff/cache   available
  Mem:           3871        1230        1782          33         858        2378
  Swap:          4004           0        4004
```
