module.exports = require('../build/Release/bigmaths.node');

module.exports.countto_jsversion = function(ubound, skip) {
    var i = 0, c = 0;
    while ( i < ubound ) {
        i += skip;
        c ++;
    }

    return c;
};

/**
 * wrap C++/JS functionality in a timer
 * @param runner - JS or C
 * @param uBound
 * @param skip
 */
module.exports.timedCountTo = function(runner, uBound, skip) {
    var starttime = new Date().getTime();
    if (runner == "JS") {
        module.exports.countto_jsversion(uBound, skip);
    } else {
        module.exports.countto(uBound, skip);
    }
    var endtime = new Date().getTime();
    var dur = (endtime - starttime)/1000;

    console.log("Counting from 0 to " + uBound + " (skipping by " + skip + ") took " + dur + " seconds with " + runner);
}