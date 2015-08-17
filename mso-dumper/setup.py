from distutils.core import setup
setup(
    name = "msodumper",
    version = "0.3.0",
    packages = ['msodumper'],
    scripts = ['ppt-dump.py'],
    data_files=[('man/man1', ['man/ppt-dump.py.1'])],
    author = "Kohei Yoshida <kohei.yoshida@collabora.com>, Thorsten Behrens <tbehrens@suse.com>",
    author_email = "libreoffice@lists.freedesktop.org",
    description = "A package for analysing and dumping MS office formats",
    license = "MPL",
    url = "http://cgit.freedesktop.org/libreoffice/contrib/mso-dumper/"
)
