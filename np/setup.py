from distutils.core import setup, Extension

mModule = Extension('PrintBinImgBits',
                        sources = ['PrintBinImgBits.c'], 
                        include_dirs=["/usr/lib/python2.7/dist-packages/numpy/core/include/numpy"],
                        library_dirs=[],
                        libraries=[])

setup (name = 'PrintBinImgBits',
        version = '1.0',
        description = 'Python PrintBinImgBits extension',
        ext_modules = [mModule])

