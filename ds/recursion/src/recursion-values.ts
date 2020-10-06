export enum Dir {
    Up,
    Down,
    Left,
    Right,
    None
}

// TODO: EDIT THESE VARIABLES FOR DIFFERENT EXPERIENCES!!!
//
// 1.  map = the map to walk.
// S = start
// * = wall
// E = end
//
//
// 2.  Dirs are the directions you wish to go
//
//
// 3.  log = true will produce the logging file, false = the base
//     implementation.
export const map: string[][] =
`
******S***
*      * E
*      * *
*        *
**********`.
    split("\n").
    // There is one new line at the top of the file, makes it easier to align
    // the map.  The map must be a rectangle of some sorts.
    slice(1).
    map((x: string) => x.split(''));

export const dirs = [
    [Dir.Down, 1, 0],
    [Dir.Left, 0, -1],
    [Dir.Up, -1, 0],
    [Dir.Right, 0, 1],
];

export const runYours = true;

