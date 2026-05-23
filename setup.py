from setuptools import setup, Extension
from Cython.Build import cythonize

ext = Extension(
    name="wrapper",
    sources=["wrapper.pyx", "Life.cpp"],
    language="c++",
)

setup(
    ext_modules=cythonize(ext)
)