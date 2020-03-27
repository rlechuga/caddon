{
    "targets": [{
        "target_name": "mathaddon",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
            "cppsrc/square-root.cpp",
            "cppsrc/samples/actualclass.cpp",
            "cppsrc/samples/classexample.cpp",
            "cppsrc/main.cpp"         
        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")"
        ],
        'libraries': [],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}