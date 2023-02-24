class Stack {  
    constructor(){  
        this.data = [];  
        this.top = 0;  
    }  
    push(element) {  
      this.data[this.top] = element;  
      this.top = this.top + 1;  
    }  
   length() {  
      return this.top;  
   }  
   peek() {  
      return this.data[this.top-1];  
   }  
   isEmpty() {  
     return this.top == 0;  
   }  
  pop() {  
    if( this.isEmpty() == false ) {  
       this.top = this.top -1;  
       return this.data.pop(); // last element gets deleted  
     }  
   }  
   print() {  
      var t = this.top - 1;   
      while(t >= 0) {   
          console.log(this.data[t]);  
           t--;  
       }  
    }  
}
let stack =  new Stack();
stack.push(1);
stack.push(2);
stack.push(3);
stack.push(4);
stack.push(5);
console.log("Stack Elements :")
stack.print();
console.log("Popped Element :");
console.log(stack.pop());
console.log("Peek Element :");
console.log(stack.peek());
console.log("Length :");
console.log(stack.length());