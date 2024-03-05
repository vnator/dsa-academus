class Nod {
    val: number;
    prev: Nod;
    next: Nod;
    constructor(val: number, prev?: Nod, next?: Nod) {
        this.val = val
        this.prev = prev ?? this;
        this.next = next ?? this;
    }
}
  
  class MyLinkedList {
    sentinel: Nod;
    length: number;
    
    constructor() {
      this.sentinel = new Nod(0);
      this.length = 0
    }
  
    getNod(index: number): Nod {
        let forward = index <= this.length / 2;
        let i = forward
            ? index + 1
            : this.length - index;
        let curr = this.sentinel;

        while (i > 0) {
            curr = forward ? curr.next : curr.prev;
            i--
        }

        return curr;
    }
    
    get(index: number): number {
        if (index < 0 || index > this.length - 1) return -1;
        return this.getNod(index).val;
    }
  
    addAtHead(val: number): void {
        this.addAtIndex(0, val)
    }
  
    addAtTail(val: number): void {
        this.addAtIndex(this.length, val)
    }
  
    addAtIndex(index: number, val: number): void {
        if (index < 0 || index > this.length) {
            return;
        }

        const head = this.getNod(index);
        const tail = head.prev;
        
        tail.next = new Nod(val, tail, head)
        head.prev = tail.next

        this.length+=1
    }
  
    deleteAtIndex(index: number): void {
        if (index < 0 || index > this.length - 1) {
            return;
        }
        
        let nod = this.getNod(index);
        let tail = nod.prev;
        let head = nod.next;

        tail.next = head
        head.prev = tail

        this.length--
    }
  }