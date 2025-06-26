**There is only on value in javascript that is not equal to itself. It is NaN**
```js
console.log(NaN==NaN);
 FALSE
```
**There are two special values undefined and Null ehich are meaningless and can be used interchangeably**
**The Number.isNaN(number) is a javascript function that returns true only if the "number" is a NaN else returns false**

**Functions and different ways of defining it**

   => **Traditional method**  :
   ```js
     function greet(name){
        console.log("Hello"+name);
     }
     greet();
   ```
=>**Function Expression** :
  ```js 
const greet =function(name){
    console.log("Hello"+name)
   }
   greet();
   ```
   
=>**Arrow expression** :
```js
   const greet=>(name){
    console.log("Hello"+name);
   }
   greet();
   ```

