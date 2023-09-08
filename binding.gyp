{
  "targets": [
    {
      "target_name": "sharedmemory",
      "sources": ["src/addon.cc"],
      "conditions":[
        ["OS=='linux'", {
          "sources": [ "src/linux/sharedmemory.cc" ]
          }],
        ["OS=='win'", {
          "sources": [ "src/windows/sharedmemory.cc", "src/windows/memory.cc" ]
        }]
      ], 
      'include_dirs': ["<!@(node -p \"require('node-addon-api').include\")"],
      'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
      'cflags!': [ '-fno-exceptions' ],
      'cflags_cc!': [ '-fno-exceptions' ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }
  ]
}
