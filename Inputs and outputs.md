# Getting inputs ready
## Define addon interfaces into WIDL files

How to write WIDL files is out scope of this document. For more details, please refer to [W3C Web IDL](https://heycam.github.io/webidl/) spec. But we have some notes and emphasis listed below except general syntax.
- Array, both the ```sequence<TypeName>``` and the normal array ```TypeName[]```, but we recommend to use sequence.
- Attributes, readonly and writable attributes are all supported, inheritant attributes has not been supported yet.
- Buffer, ArrayBuffer and typed array are all supported.
- Overloaded methods and optional arguments are all supported, but method-overload is recommended. 
- Primitive types are supported except ``` long long```, WIDL-NAN can handle ```long long```, it will be transformed as ```int64_t```, but the JavaScript engine [V8](https://github.com/v8/v8) can't support 64-bit numbers.
- Event emitter has not been supported directly, JavaScript Wrapper can be used to achive the goal, please refer [this example](https://github.com/otcshare/node-realsense/blob/master/src/slam/index.js#L13).

For more detail or samples, please check the examples under https://github.com/01org/widl-nan/tree/master/test, basically each supported feature has a test case.

# Outputs
