const fs = require("fs");

function transform(N, P) {
  // Convert the integer to a string
  const n_str = N.toString();
  // Find the Pth digit from the right
  const p_digit = n_str[n_str.length - P];
  // Initialize an empty string to store the result
  let result = "";
  // Iterate over the characters in n_str
  for (let i = 0; i < n_str.length; i++) {
    // If the character is to the left of the Pth digit
    if (i < n_str.length - P) {
      // Append the sum of the digit and p_digit to result. If the sum is greater than 9, use the units digit.
      result += ((parseInt(n_str[i]) + parseInt(p_digit)) % 10).toString();
    }
    // If the character is the Pth digit
    else if (i === n_str.length - P) {
      // Append it to result without change
      result += n_str[i];
    }
    // If the character is to the right of the Pth digit
    else {
      // Append the absolute value of the difference between it and p_digit to result
      result += Math.abs(parseInt(n_str[i]) - parseInt(p_digit)).toString();
    }
  }
  // Convert result to an integer and return it
  return parseInt(result);
}

fs.readFile("input.txt", "utf8", (err, data) => {
  if (err) throw err;
  const lines = data.split("\n");
  for (let line of lines) {
    const [n, p] = line.split();
    const numbers = n.split("  ");
    const result = transform(parseInt(numbers[0]), parseInt(numbers[1]));
    console.log(result);
  }
});
