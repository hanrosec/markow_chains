# C++ implementation of Markow Chains

by Hanrose

## Example

```c++
ifstream file("file.txt");
string words((istreambuf_iterator<char>(file)),
    istreambuf_iterator<char>()); // Reading whole file

cout << "Processing words\n";
vector<string> processed = get_unique_string(words, " "); // getting unique keys
cout << "Words processed\n";

Chain *chain = new Chain(); // Constructing chain

cout << "Preprocessing data\n";
chain->preprocess_data(words, " "); // Processing data to get int keys from words
cout << "data preprocessed\n";

chain->train(chain->get_preprocessed_data()); // training model

vector<int> result = chain->generate(0, 12); // generating text with given first word (key) and with length

for (int i : result) cout << chain->get_tags().find(i)->second << ' '; // printing generated text
cout << '\n';
```

## file.txt

```plain
hello world Github hello Github
```

## Output

```plain
Processing words
Words processed
Preprocessing data
data preprocessed
hello world Github hello Github hello world Github hello world Github hello world
```
