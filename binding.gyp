{
    "targets": [
    {
        "target_name": "helloworld",

        "sources": [
            "src/helloworld.cpp" ],

        "include_dirs" : [
            "<!(node -e \"require('nan')\")"
        ]
    },

    {
        "target_name": "randomcoords",

        "sources": [
            "src/randomcoords.cpp" ],

        "include_dirs" : [
            "<!(node -e \"require('nan')\")"
        ]
    }
  ]
}