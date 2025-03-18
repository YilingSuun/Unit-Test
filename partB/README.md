# Part B - Red Black Tree

This part assumes you already have knowledge of Google Tests and how to write unit tests. If you
don't, you should do part A first.

This part will be similar to part A with a couple of key differences:

* You are not given the implementation file, only the header file
* There are a lot more mutants
* Hints are a little more vague and less helpful

## Provided Files

For this part, we have not provided the actual `redblacktree.cc` file, but we have provided `redblacktree.h` (it's in
the `include` folder).  Use `redblacktree.h` to figure out functions of the redblacktree class are and how
they should be called.

Additionally, we have provided `redblacktree.o`, a compiled version of `redblacktree.cc` that
you can use to locally run your programs. You may assume that `redblacktree.o` is the correct version of the
code.

We have also provided a template `main.cc` file that shows example usage of the redblacktree class. Feel free
to edit this file as much as you want (you won't be submitting it anyways). You can compile and
run the code you write in `main.cc` with:

(*code templates assume you are in the current directory*)

```bash
make

./redblacktree
```

Use the `main.cc` file to clarify any questions or confusions about the expected behavior of the
redblacktree class.

Finally, we have provided a template `redblacktree_unittest.cc` file. You will have to fill this file out
with your own unit tests and submit it to Gradescope. At any time, you can run your tests against the
correct version of the code with:

```bash
make

./redblacktree_unittest
```

Since it is being run against the *correct* version of the code, all of your tests should *pass*. If
your tests do not *pass* when you run it locally, then that means that your tests are not correctly using
the redblacktree class. Again, you can use the `main.cc` file to understand how to correctly use the class and
test stuff out there.

## **Submission**

Submit your work by uploading the `redblacktree_unittest.cc` file to Gradescope. You can upload as many times
as you want until the deadline. Note that if your tests do not *pass* against the *correct* version of
the code (which you can test locally), you will not receive any points for catching the mutants.

### Notes

* Ensure that the file you submit is named exactly `redblacktree_unittest.cc`, otherwise the autograder will not use your file and instead use the empty template file.
