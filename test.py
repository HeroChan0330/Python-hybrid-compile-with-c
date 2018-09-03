import ctypes

libc=ctypes.cdll.LoadLibrary("./CFile/hello.so")
libc.helloWorld()
print(libc.plus(3))