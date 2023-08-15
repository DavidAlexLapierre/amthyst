export class MyClass {
    thisIsATestFunction = () => {
        const a = 3;
        const b = 7;
        const c = a * b / a / 7;
        console.log(c);
    }    
}

export const test = (test: MyClass) => {
    test.thisIsATestFunction();
}