public class Main {
public static void main(String[] args) {
char c = 34;
String[] str = {
"public class Main {",
"public static void main(String[] args) {",
"char c = 34;",
"String[] str = {",
"",
"};",
"for (int i = 0; i < 4; i++) System.out.println(str[i]);",
"for (int i = 0; i < str.length; i++) System.out.println(str[4] + c + str[i] + c + ',');",
"for (int i = 5; i < str.length; i++) System.out.println(str[i]);",
"}",
"}",
};
for (int i = 0; i < 4; i++) System.out.println(str[i]);
for (int i = 0; i < str.length; i++) System.out.println(str[4] + c + str[i] + c + ',');
for (int i = 5; i < str.length; i++) System.out.println(str[i]);
}
}