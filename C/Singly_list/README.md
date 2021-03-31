# Singly list usage:

## Description:
    **Function support:**
        1. Add data {any primitive or structure} to head of the list.
        2. Add data to the tail of the list.
        3. Retrieve data which had been stored at head of list.
        4. Retrieve data which had been stored at tail of list.
        5. Add label to list {any data type.}

**Before use:** Have a address of data ready {either through allocate new data
or use address of existed data} pass them into constructor.

**NOTE:** You can insert straight list without first create it. The insertion
method will handle create the list.
**NOTE2:** When free: this method will also free every data address in the
list.
**NOTE3:** function 3 & 4 will return void pointer. Will need to do type-cast,
to get back what insert to this list.
