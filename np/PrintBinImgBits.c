#include <Python.h>
#include <ndarraytypes.h>
#include <stdio.h>
static PyObject * printBinImgBits(PyObject *self, PyObject *args) {
    PyObject *o;
    if (!PyArg_ParseTuple(args, "O", &o))
        return NULL;

    PyObject *ao = PyObject_GetAttrString(o, "__array_struct__");

    PyArrayInterface *pai = (PyArrayInterface*)PyCObject_AsVoidPtr(ao);


    char *buffer = (char*)pai->data; // The address of image data
    int width = pai->shape[1];       // image width
    int height = pai->shape[0];      // image height
    int size = pai->strides[0] * pai->shape[0]; // image size = stride * height
    int stride = pai->strides[0];

    for(int j=0;j<height;j++){
        for(int i=0;i<width;i++){
        unsigned char content=(unsigned char)*(buffer + stride * (j)+i);
            printf("%d ",content);
        }
        printf("\n");
    }
    PyObject* retval = Py_BuildValue("i", 666);
    return retval;
}
//method to be registered
static PyMethodDef Methods[] ={
     {"printBinImgBits", printBinImgBits, METH_VARARGS, NULL},
     {NULL, NULL, 0, NULL}
};

//initilize function
PyMODINIT_FUNC
initPrintBinImgBits(void){
     printf("PrintBinImgBits Init\n");
	(void) Py_InitModule("PrintBinImgBits", Methods);
}

