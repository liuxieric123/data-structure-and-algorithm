package hashTable;

import java.util.*;

public class longestPalindrom {
    public int solution (String s) {
        int odd = 0;
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); ++i) {
            if (!map.containsKey(s.charAt(i))) {
                map.put(s.charAt(i), 1);
            } else {
                map.put(s.charAt(i), map.get(s.charAt(i)+1));
            }
        }
        for (Character key: map.keySet()){
            if ((map.get(key) % 2) == 1) odd += 1;
        }

        return s.length() - Math.max(0, odd-1);
    }
}