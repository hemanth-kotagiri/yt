type BNode = {
    value: number;
    left: BNode | null;
    right: BNode | null;
}

function binarySearchTree(curr: BNode, v: number): boolean {
    if (curr === null) {
        return false;
    }

    if (curr.value === v) {
        return true;
    }
    else if (curr.value > v) {
        return binarySearchTree(curr.left, v);
    }
    return binarySearchTree(curr.right, v);
}

function binarySearchList(arr: number[], v: number): number {
    let L = 0;
    let R = arr.length - 1;

    while (L <= R) {
        const idx = L + Math.floor((R - L) / 2);
        const value = arr[idx];
        if (value === v) {
            return idx;
        }
        else if (value > v) {
            R = idx - 1;
        }
        else {
            L = idx + 1;
        }
    }

    return -1;
}

const list = [1, 5, 7, 9, 11, 15, 17];

console.log(binarySearchList(list, 1));
console.log(binarySearchList(list, 13));
console.log(binarySearchList(list, 17));

const head: BNode = {
    value: 10,
    left: {
        value: 8,
        left: {
            value: 3,
            right: null,
            left: {
                value: 1,
                right: null,
                left: null
            }
        },
        right: {
            value: 9,
            right: null,
            left: null,
        }
    },
    right: {
        value: 12,
        left: {
            value: 11,
            left: null,
            right: null,
        },
        right: {
            value: 15,
            left: {
                value: 14,
                left: {
                    value: 13,
                    left: null,
                    right: null,
                },
                right: null
            },
            right: null,
        }
    }
};

console.log(binarySearchTree(head, 1));
console.log(binarySearchTree(head, 13));
console.log(binarySearchTree(head, 17));
