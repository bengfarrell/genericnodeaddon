var hw = require('./lib/helloworld.js');
console.log("Calling Hello(): " + hw.hello());


var rc = require('./lib/randomcoords.js');
console.log( "1st pass 2D: ", rc.getRandomCoords2D(100, 200) );
console.log( "2nd pass 2D: ", rc.getRandomCoords2D(100, 200) );
console.log( "3rd pass 2D: ", rc.getRandomCoords2D(100, 200) );

console.log( "1st pass 3D: ", rc.getRandomCoords3D(100, 200, 100) );
console.log( "2nd pass 3D: ", rc.getRandomCoords3D(100, 200, 100) );
console.log( "3rd pass 3D: ", rc.getRandomCoords3D(100, 200, 100) );

var bm = require('./lib/bigmaths.js');
bm.timedCountTo("C", 1000000000, 1);
bm.timedCountTo("JS", 1000000000, 1);