package backtracking;

import java.util.*;

public class generateParentheses {
    public List <String> solution (int n){
        List <String> result = new ArrayList <>();
        generate(result, "", n, n);
        return result;
    }
// 关键点：一左括号在什么时候放置都是合法的；二是存在的左括号数量大于右括号数量时放置右括号是合法的
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