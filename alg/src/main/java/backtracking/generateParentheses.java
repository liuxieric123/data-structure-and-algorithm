package backtracking;

import java.util.*;

public class generateParentheses {
    public List <String> solution (int n){
        List <String> result = new ArrayList <>();
        generate(result, "", n, n);
        return result;
    }

    public void generate (List <String> result, String str, int left, int right) {
        if (left == 0 && right == 0) {
            result.add(str);
            return;
        } else {
            if (left > 0) generate(result, str+"(", left-1, right);
            if (right > left) generate(result, str+")", left, right-1);
        }
    }
}