# Unit Test

A formal testing framework, such as Google Test, provides a powerful and convenient mechanism for testing your code. It does this without requiring you to modify your source code or pollute it with test statements.

Tests primarily consist of a comparison of an expected result to a calculated result. If they match, the test is reported as passed, if not, it reports a fail. For unit tests, you will create a separate test for each class method, which is a collection of statements to compare expected and calculated results based on a variety of input.

Think carefully about the range of input to a given method to ensure the code is thoroughly tested. For example, if you were trying to test a function that calculated a fibonacci number, you would want to consider boundary cases such as 1 and 2, some normal cases such as 3 and 8, some error cases such as -1 and 3.6, and then there is 0. Is this an error or do you define it as 0? It could be either, but maybe you need to ask someone how this should be handled. As you are writing tests, you will often reveal ambiguities in the specifications, which is another excellent reason to write code with testing in mind (and even to write requirements with testing in mind)!

For this class, we will be using the Google C++ Testing Framework.
