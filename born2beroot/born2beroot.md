## Meta

CentOS is supported by Red Hat. It uses red hat linux.
Its more supported. Bigger community. Critical servers
are hosted on it. But does not support many different
architectures. And every version is supported for 10
years.
	New versions are released after longer gaps.

Debian is unix like. Ubuntu, Kali, etc. are variant of Debian.

`wajig` - Is a wrapper around many apt tools like `apt-mark` `apt-cache`
`apt`	- Better commands, for users
`aptitued` - UI interface

`APPArmor` - Kernel security module. Restrict by _per app_ configs.


## Commands

### Check install
`dpkg -l <pkg_name>`

### Passwords

`/etc/login.defs` - Expiration
`/etc/pam.d/common-password`

`passwd` - Change user passwd
`passwd <usr>`

#### pam pwquality notes
`difok` - Number of character changes accepted
The following are for password simplicity

`minlen`
`maxclassrepeat`
`dcredit` - Max digit credit
`ucredit` - Credit for uppercase 
`lcredit` - "" for lowercase letters
`ocredit` - "" for other letters
 
`Cracklib` - To check if the password is a part of a library

### App armor

enforce  - blocking
complain - it allows but it will log it

`systemctl status apparmor` # Check if it is running

`aa-status` # App armor status, configs etc.

### Sudo

`secure_path` # Replaces PATH with this
`man 5 sudoers` # All the options are here

### Hostname
`hostnamectl` - Tons of info
`hostnamectl set-hostname <new_name>` and change /etc/hosts
`hostname` # Print hostname
`/etc/hostname`
`/etc/hosts`
`nmap -sT -O <username>` # Open ports
`-sT` tcp scan
`-O`  OS dedection thing


### Users

Primary group is what gets attached to the file
that user creates.

`gpasswd --delete <user> <group>` - Remove user from group
`groupadd <name>`
`groupdel <name>`
`useradd -g <primary_group> -G <g2>,<g3> <username>`

`groups <username>`

`id username`

a - append, unless it will remove all from
all the groups and only add it to that

G - for  group,  this  specifies the group
name
`usermod -aG groupname username`

### SSH

`systemctl status ssh`
`/etc/ssh/sshd_config`

`sudo service ssh start/stop` - Doesn't work for existing ssh connections

meh
`/etc/init.d/sshd restart` # restarts the ssh daemon
`service sshd restart`

### UFW

Denies everything by default

`ufw status verbose/numbered`
`ufw enable`
`ufw default deny/allow incoming/outgoing` # alter the default behaviour

`ufw allow/deny 4242/tcp...`
`ufw delete <rule_number>`

### monitoring.sh

`df` - Report file system disk space usage. `-h` 250MB 3GB like numbes
`free` - Amount of free mem in MB for `-m`
`top` - htop thing.  `-b` for batched output, `-n1` for processing it one frame
`who` - Who is currently is logged in



``
