Name:           mso-dumper
# List of additional build dependencies
Requires:       python
BuildRequires:  python
Version:        0.2
Release:        1
BuildArch:      noarch
License:        MPLv2
Packager:       Kohei Yoshida  <kohei.yoshida@collabora.com>
Source:         mso-dumper-0.2.tar.gz
Group:          Development/Tools/Debuggers
Summary:        Dumper tool for Microsoft Office binary file format

BuildRoot:      %{_tmppath}/%{name}-%{version}-build

%description
This package provides dumper scripts for dumping the contents of Microsoft
Office binary file formats.  Currently only the Excel and PowerPoint file
formats are supported.


Authors:
--------
    Kohei Yoshida <kohei.yoshida@collabora.com>
    Thorsten Behrens <tbehrens@suse.com>
    Miklos Vajna <vmiklos@collabora.com>
    Noel Power <nopower@suse.com>
    Jean-Francois Dockes <jf@dockes.org>
    Sergey Kishchenko <voidwrk@gmail.com>
    Fredrik Ekholdt (for xmlpp.py)
    and contributors

%prep
%setup -q

%build
mkdir -p %buildroot/usr/bin
mkdir -p %buildroot/usr/share/mso-dumper-%version/src
mkdir -p %buildroot/usr/share/doc/packages/mso-dumper-%version
cp xls-dump.py %buildroot/usr/share/mso-dumper-%version/
cp ppt-dump.py %buildroot/usr/share/mso-dumper-%version/
cp src/*.py %buildroot/usr/share/mso-dumper-%version/src

%install
install -d %buildroot/usr/share/mso-dumper-%version
#install -d %buildroot/usr/share/doc/packages/mso-dumper-%version
cd %buildroot/usr/bin
ln -s ../share/mso-dumper-%version/xls-dump.py xls-dump
ln -s ../share/mso-dumper-%version/ppt-dump.py ppt-dump

%clean
rm -rf %buildroot

%files
%defattr(-,root,root)
%dir /usr/share/doc/packages/mso-dumper-%version
%dir /usr/share/mso-dumper-%version
%dir /usr/share/mso-dumper-%version/src

/usr/bin/xls-dump
/usr/bin/ppt-dump
/usr/share/mso-dumper-%version/xls-dump.py
/usr/share/mso-dumper-%version/ppt-dump.py
/usr/share/mso-dumper-%version/src/ole.py
/usr/share/mso-dumper-%version/src/formula.py
/usr/share/mso-dumper-%version/src/globals.py
/usr/share/mso-dumper-%version/src/node.py
/usr/share/mso-dumper-%version/src/pptstream.py
/usr/share/mso-dumper-%version/src/pptrecord.py
/usr/share/mso-dumper-%version/src/xlsstream.py
/usr/share/mso-dumper-%version/src/xlsmodel.py
/usr/share/mso-dumper-%version/src/xlsrecord.py
/usr/share/mso-dumper-%version/src/xmlpp.py

#%doc AUTHORS COPYING ChangeLog INSTALL NEWS README README-WIN32 TODO

%changelog
* Wed Mar 17 2010 kyoshida@novell.com
- Initial package version 0.2.

  
