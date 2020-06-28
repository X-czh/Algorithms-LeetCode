class Solution {
    public boolean isValid(String s) {
        if (s == null)
            return true;
        
        Stack<Character> stack = new Stack<Character>();
        for (int i = 0; i < s.length(); i++) {
            Character ch = s.charAt(i);
            switch (ch) {
                case '(': case '{': case '[':
                    stack.push(ch);
                    break;
                case ')':
                    if (stack.empty() || (stack.pop() != '(')) {
                        return false;
                    }
                    break;
                case '}':
                    if (stack.empty() || (stack.pop() != '{')) {
                        return false;
                    }
                    break;
                case ']':
                    if (stack.empty() || (stack.pop() != '[')) {
                        return false;
                    }
                    break;
            }
        }
        
        return stack.empty();
    }
}