export interface DataNode<T> {
    data: T;
    next: DataNode<T> | null;
}

export interface IQueue<T> {
    enqueue(data: T): void;
    dequeue(): T | null;
    peek(): T | null;
    size(): number;
}

export interface IStack<T> {
    push(data: T): void;
    pop(): T | null;
    peek(): T | null;
    size(): number;
}

export interface IDoublyLinked<T> {
    enqueue(data: T): void; // O(1)
    dequeue(): T | null; // O(1)
    push(data: T): void; // O(1)
    pop(): T | null; // O(1)
    getAt(index: number): T; // O(n)
    insertAt(index: number, data: T): void; // O(n)
    removeAt(index: number): void; // O(n)
    size(): number;
}

export class Queue<T> implements IQueue<T> {
    private _size: number;
    private head: DataNode<T> | null;
    private tail: DataNode<T> | null;
    constructor() {
        this._size = 0;
        this.head = this.tail = null;
    }

    size(): number {
        return this._size;
    }

    enqueue(data: T): void {
        const node: DataNode<T> = {
            data,
            next: null
        };

        if (this.head === null) {
            this.head = this.tail = node;
        } else {
            this.tail.next = node;
            this.tail = this.tail.next;
        }

        ++this._size;
    }

    dequeue(): T | null {
        if (this._size == 0) {
            return null;
        }

        const item = this.head.data;
        this.head = this.head.next;
        --this._size;

        return item;
    }

    peek(): T | null {
        if (this._size == 0) {
            return null;
        }

        return this.head.data;
    }
}

export class Stack<T> implements IStack<T> {
    private _size: number;
    private tail: DataNode<T> | null;

    constructor() {
        this._size = 0;
        this.tail = null;
    }

    size(): number {
        return this._size;
    }

    push(data: T): void {
        const node: DataNode<T> = {
            data,
            next: null
        };

        if (this.tail === null) {
            this.tail = node;
        } else {
            node.next = this.tail;
            this.tail = node;
        }

        ++this._size;
    }

    pop(): T | null {
        if (this._size == 0) {
            return null;
        }

        const item = this.tail.data;
        this.tail = this.tail.next;
        --this._size;

        return item;
    }

    peek(): T | null {
        if (this._size == 0) {
            return null;
        }

        return this.tail.data;
    }
}
