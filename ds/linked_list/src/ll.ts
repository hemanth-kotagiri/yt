export interface DataNode<T> {
    data: T;
    next: DataNode<T> | null;
}

export interface ILinkedList<T> {
    head: DataNode<T>;
    push(data: T): number;
    pop(): T;
    size(): number;
}

export class LinkedList<T> implements ILinkedList<T> {
    private tail: DataNode<T>;
    private _size: number;
    public head: DataNode<T>;

    constructor() { }

    size(): number {
        return this._size;
    }

    push(data: T): number {
        this._size++;

        if (this.head == null) {
            this.head = this.tail = {
                data,
                next: null,
            };
            return this._size;
        }

        this.tail.next = {
            data,
            next: null
        };
        this.tail = this.tail.next;
        return this._size;
    }

    pop(): T | undefined {
        if (this._size == 0) {
            return undefined;
        }

        this._size--;
    }
}


