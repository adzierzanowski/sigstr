# sigstr (signal strength)

This is a utility to spit out some Wi-Fi stats. What makes it a little bit
interesting is that I provide a small wrapper over `CWInterface` from macOS
API in Swift. Then I generate assembly and demangle the names so I can link to
the code with C.

It's probably the stupid way to obtain this information but it was fun.
