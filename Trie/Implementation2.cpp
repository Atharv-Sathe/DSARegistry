#include <bits/stdc++.h>
using namespace std;

class Trie {
 private:
  struct TrieNode {
    TrieNode* links[26];
    bool isEnd = false;
    int count = 0;

    bool hasLink(char ch) { return links[ch - 'a'] ? true : false; }

    TrieNode* getLink(char ch) { return links[ch - 'a']; }

    void setLink(char ch, TrieNode* node) { links[ch - 'a'] = node; }

    void setEnd() {
      isEnd = true;
      count++;
    }

    bool isEmpty() {
      for (int i = 0; i < 26; i++) {
        if (links[i]) return false;
      }
      return true;
    }

    bool isWordEnd() { return isEnd; }
  };
  TrieNode* root;

  int countWordsHelper(TrieNode* node) {
    int count = node->count;
    for (int i = 0; i < 26; i++) {
      if (node->links[i] == nullptr) continue;
      count += countWordsHelper(node->links[i]);
    }
    return count;
  }

  TrieNode* eraseHelper(TrieNode* node, string& word, int depth) {
    if (!node) return nullptr;

    // If we are at the end of the word
    if (depth == word.size()) {
      if (node -> isWordEnd()) {
        node->count--;
        // If node count becomes 0 then this is no longer a word ending
        if (node->count == 0) {
          node->isEnd = false;
        }     
      }
      // Delete node if it's no longer a word end and has no children
      return (node -> isWordEnd() || !node -> isEmpty()) ? node : nullptr;
    }

    // Recurse Down
    int index = word[depth] - 'a';
    node->links[index] = eraseHelper(node->links[index], word, depth + 1);

    // Delete node if it's no longer a word end and has no children
    return (node -> isWordEnd() || !node -> isEmpty()) ? node : nullptr;
  }

 public:
  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode* node = root;
    for (int i = 0; i < word.size(); i++) {
      if (!(node->hasLink(word[i]))) {
        // Create a new link at this position
        TrieNode* newNode = new TrieNode();
        node->setLink(word[i], newNode);
      }
      // Move to the next link
      node = node->getLink(word[i]);
    }
    node->setEnd();
  }

  bool search(string word) {
    TrieNode* node = root;
    for (int i = 0; i < word.size(); i++) {
      if (!(node->hasLink(word[i])))
        return false;
      else {
        node = node->getLink(word[i]);
      }
    }
    return node->isWordEnd();
  }

  bool startsWith(string prefix) {
    TrieNode* node = root;
    for (int i = 0; i < prefix.size(); i++) {
      if (!(node->hasLink(prefix[i])))
        return false;
      else
        node = node->getLink(prefix[i]);
    }
    return true;
  }

  int countWordsEqualTo(string word) {
    TrieNode* node = root;
    for (int i = 0; i < word.size(); i++) {
      if (!(node->hasLink(word[i])))
        return 0;
      else {
        node = node->getLink(word[i]);
      }
    }
    return node->count;
  }

  int countWordsStartingWith(string prefix) {
    TrieNode* node = root;
    for (int i = 0; i < prefix.size(); i++) {
      if (!(node->hasLink(prefix[i]))) return 0;

      node = node->getLink(prefix[i]);
    }
    return countWordsHelper(node);
  }

  void erase(string& word) { eraseHelper(root, word, 0); }
};

// Helper function to print test results
void printTestResult(int testNum, const std::string& description, bool passed) {
  std::cout << "Test " << testNum << " (" << description
            << "): " << (passed ? "PASSED" : "FAILED") << std::endl;
}

int main() {
  std::cout << "Starting Trie Test Suite..." << std::endl;
  std::cout << "--------------------------------" << std::endl;

  // Test 1: Basic Operations
  Trie t1;
  std::string w1 = "hello", w2 = "world";
  t1.insert(w1);
  t1.insert(w2);
  printTestResult(1, "Basic Insert & Search",
                  t1.search(w1) && t1.search(w2) && t1.startsWith("hell"));

  // Test 2: Duplicate Insertions and countWordsEqualTo
  Trie t2;
  std::string w3 = "apple";
  t2.insert(w3);
  t2.insert(w3);
  t2.insert(w3);
  printTestResult(
      2, "countWordsEqualTo",
      t2.countWordsEqualTo(w3) == 3 && t2.countWordsEqualTo(w1) == 0);

  // Test 3: Prefix & Word Overlap
  Trie t3;
  std::string p1 = "app", p2 = "apple", p3 = "apply";
  t3.insert(p1);
  t3.insert(p2);
  t3.insert(p3);
  bool test3_passed = t3.search(p1) && t3.search(p2) && !t3.search("appl") &&
                      t3.startsWith("app") &&
                      t3.countWordsStartingWith(p1) == 3;
  printTestResult(3, "Prefix & Word Overlap", test3_passed);

  // Test 4: Non-Existent Entries
  Trie t4;
  std::string w4 = "banana";
  t4.insert(w4);
  bool test4_passed = !t4.search("bandana") && !t4.startsWith("cat") &&
                      t4.countWordsEqualTo("bandana") == 0 &&
                      t4.countWordsStartingWith("cat") == 0;
  printTestResult(4, "Non-Existent Entries", test4_passed);

  // Test 5: Complex Counting
  Trie t5;
  std::vector<std::string> words = {
      "data", "database", "datastructure", "date", "datum", "dog", "dogma"};
  for (std::string& word : words) t5.insert(word);
  t5.insert(words[0]);  // insert "data" again
  bool test5_passed = (t5.countWordsStartingWith("dat") == 6) &&
                      (t5.countWordsStartingWith("data") == 4) &&
                      (t5.countWordsStartingWith("dog") == 2) &&
                      (t5.countWordsEqualTo(words[0]) == 2);
  printTestResult(5, "Complex Prefix Counting", test5_passed);

  // Test 6: Empty Prefix (should count all words)
  printTestResult(
      6, "Empty Prefix Count",
      t5.countWordsStartingWith("") == 8);  // 7 unique + 1 duplicate

  // Test 7: Empty String Insertion
  Trie t7;
  std::string empty_str = "";
  t7.insert(empty_str);
  t7.insert(empty_str);
  bool test7_passed = t7.search(empty_str) &&
                      (t7.countWordsEqualTo(empty_str) == 2) &&
                      (t7.countWordsStartingWith("") == 2);
  printTestResult(7, "Empty String Handling", test7_passed);

  // // Test 8: Character Case
  // Trie t8;
  // std::string w_lower = "case";
  // std::string w_upper =
  //     "CASE";  // Should not be insertable in your current trie
  // t8.insert(w_lower);
  // // Your trie only handles 'a'-'z'. A robust trie might handle this
  // // differently. This test just confirms the current behavior.
  // printTestResult(8, "Character Case Sensitivity",
  //                 t8.search(w_lower) && !t8.startsWith("C"));

  // Test 9: Deeply Nested Word
  Trie t9;
  std::string long_word = "abcdefghijklmnopqrstuvwxyz";
  t9.insert(long_word);
  bool test9_passed = t9.search(long_word) && t9.startsWith("abcdefg") &&
                      t9.countWordsEqualTo(long_word) == 1 &&
                      !t9.search("abcdefghijklmnopqrstuvwxy");
  printTestResult(9, "Long Word Traversal", test9_passed);

  // Test 10: Mixed Operations
  Trie t10;
  std::string s1 = "test", s2 = "testing", s3 = "tester";
  t10.insert(s1);
  t10.insert(s2);
  bool r1 = t10.countWordsStartingWith("test") == 2;
  t10.insert(s3);
  bool r2 = t10.countWordsStartingWith("test") == 3;
  t10.insert(s1);
  bool r3 = t10.countWordsEqualTo(s1) == 2;
  bool r4 = t10.countWordsStartingWith("test") == 4;
  printTestResult(10, "Mixed Operations State", r1 && r2 && r3 && r4);

  std::cout << "--- Starting Erase Method Tests ---" << std::endl;

  // Test 11: Simple Erase
  Trie t11;
  std::string w11 = "simple";
  t11.insert(w11);
  t11.erase(w11);
  printTestResult(11, "Simple Erase",
                  !t11.search(w11) && t11.countWordsEqualTo(w11) == 0 &&
                      !t11.startsWith("s"));

  // Test 12: Erase a Prefix Word
  Trie t12;
  std::string w12_short = "run", w12_long = "runner";
  t12.insert(w12_short);
  t12.insert(w12_long);
  t12.erase(w12_short);
  bool r12 =
      !t12.search(w12_short) && t12.search(w12_long) && t12.startsWith("run");
  printTestResult(12, "Erase Prefix Word", r12);

  // Test 13: Erase a Longer Word
  Trie t13;
  std::string w13_short = "bug", w13_long = "buggy";
  t13.insert(w13_short);
  t13.insert(w13_long);
  t13.erase(w13_long);
  bool r13 = t13.search(w13_short) && !t13.search(w13_long) &&
             t13.countWordsStartingWith("bug") == 1;
  printTestResult(13, "Erase Longer Word", r13);

  // Test 14: Erase Non-Existent Word
  Trie t14;
  std::string w14 = "hello";
  std::string w14_non_existent = "world";
  t14.insert(w14);
  t14.erase(w14_non_existent);  // should have no effect
  printTestResult(14, "Erase Non-Existent Word",
                  t14.search(w14) && t14.countWordsEqualTo(w14) == 1);

  // Test 15: Erase with Duplicates
  Trie t15;
  std::string w15 = "code";
  t15.insert(w15);
  t15.insert(w15);
  t15.insert(w15);  // count = 3
  t15.erase(w15);   // count = 2
  bool r15_1 = t15.search(w15) && t15.countWordsEqualTo(w15) == 2;
  t15.erase(w15);  // count = 1
  bool r15_2 = t15.search(w15) && t15.countWordsEqualTo(w15) == 1;
  t15.erase(w15);  // count = 0
  bool r15_3 = !t15.search(w15) && t15.countWordsEqualTo(w15) == 0;
  printTestResult(15, "Erase With Duplicates", r15_1 && r15_2 && r15_3);

  // Test 16: Complete Path Removal
  Trie t16;
  std::string w16_1 = "test", w16_2 = "team";
  t16.insert(w16_1);
  t16.insert(w16_2);
  t16.erase(w16_1);
  bool r16_1 = t16.startsWith("te") && !t16.startsWith("tes");
  t16.erase(w16_2);
  bool r16_2 = !t16.startsWith("t");  // The entire 't' path should be gone
  printTestResult(16, "Complete Path Removal", r16_1 && r16_2);

  std::cout << "--------------------------------" << std::endl;
  std::cout << "Test Suite Finished." << std::endl;

  return 0;
}