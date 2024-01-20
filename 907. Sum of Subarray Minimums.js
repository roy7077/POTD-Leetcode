// Monotonic approach
// Time complexiity - O(N)
// Space complexity- O(2*N)
var sumSubarrayMins = function(arr) {
    const length = arr.length;
    const left = new Array(length).fill(-1);
    const right = new Array(length).fill(length);
    const stack = [];

    for (let i = 0; i < length; ++i) {
        while (stack.length > 0 && arr[stack[stack.length - 1]] >= arr[i]) {
            stack.pop();
        }
        if (stack.length) 
        left[i] = stack[stack.length - 1];
        
        stack.push(i);
    }

    stack.length = 0;
    for (let i = length - 1; i >= 0; --i) {
        while (stack.length > 0 && arr[stack[stack.length - 1]] > arr[i]) {
            stack.pop();
        }
        
        if (stack.length) 
        right[i] = stack[stack.length - 1];
        
        stack.push(i);
    }

    let sum = 0;
    const mod=1e9+7;
    for (let i = 0; i < length; ++i) {
        sum += (i - left[i]) * (right[i] - i) * arr[i] % mod;
        sum %= mod;
    }

    return sum;
};