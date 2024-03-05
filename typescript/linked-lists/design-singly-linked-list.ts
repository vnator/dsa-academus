interface Nod {
    val: number
    next: Nod
}
  
class MyLinkedList {
head: Nod;
length: number;

constructor() {
    this.head = null
    this.length = 0
}

getNod(index: number): Nod | null {
    if (index < 0 || index >= this.length) return null
    let count = 0
    let nod = this.head
    while (count < index) {
    nod = nod.next
    count++
    }

    return nod
}

get(index: number): number {
    const nod = this.getNod(index)
    return nod ? nod.val : -1
}

addAtHead(val: number): void {
    const next = this.head
    this.head = { val, next }
    this.length++
}

addAtTail(val: number): void {
    if (!this.length) {
    this.addAtHead(val)
    } else {
        const nod = this.getNod(this.length - 1)
        nod.next = { val, next: null }
        this.length++
    }
}

addAtIndex(index: number, val: number): void {
    if (index < 0 || index > this.length) return
    else if (index == this.length) {
    this.addAtTail(val)
    } else if (index == 0) {
    this.addAtHead(val)
    } else {
        const nod = this.getNod(index - 1)
        nod.next = { val, next: nod.next}
        this.length++
    }
}

deleteAtIndex(index: number): void {
    if (index < 0 || index >= this.length || !this.length) return
    else if (!index) this.head = this.head.next
    else {
        const nod = this.getNod(index - 1)
        nod.next = nod.next?.next || null
    }
    this.length--
}
}