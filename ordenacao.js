/* let numbers = Array.from({ length: 150 }, () => Math.floor(Math.random() * 10));

function ordenar(numbers) {
  for (let i = 0; i < numbers.length; i++) {
    console.log("Vetor desorganizado: ", numbers[i]);
  }

  for (let t = 1; t < numbers.length; t++) {
    let key = numbers[t];
    let j = t - 1;

    while (j >= 0 && numbers[j] > key) {
      numbers[t] = numbers[j];
      j = j - 1;
    }

    numbers[j + 1] = key;
  }

  return numbers;
}

let arrayOrg = ordenar(numbers);
console.log(arrayOrg);
 */
