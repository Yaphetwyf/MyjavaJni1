package com.example.yaphet.myjavajni;

import android.util.Log;

/**
 * Created by WYF on 2017/10/26.
 */

public class JNI {
    static {
        System.loadLibrary("native-lib");
    }
    /**
     * 从java传入字符串，C代码进程拼接
     *
     * @param s I am from java
     * @return  I am form java add I am from C
     */
    public native String hello(String s);
    /**
     * 让C代码做加法运算，把结果返回
     * @param x
     * @param y
     * @return
     */
    public native int add(int x, int y);
    /*
     * 应用: 检查密码是否正确, 如果正确返回200, 否则返回400
     */
    public native int checkPwd(String pwd);


    /**
     * 当执行这个方法的时候，让C代码调用
     * public int add(int x, int y)
     */
    public native void callbackAdd();

    /**
     * 当执行这个方法的时候，让C代码调用
     * public void helloFromJava()
     */
    public native void callbackHelloFromJava();


    /**
     * 当执行这个方法的时候，让C代码调用void printString(String s)
     */
    public native void callbackPrintString();

    /**
     * 当执行这个方法的时候，让C代码静态方法 static void sayHello(String s)
     */
    public native void callbackSayHello();




    public int addd(int x, int y) {
        Log.e("TAG", "add() x=" + x + " y=" + y);
        return x + y;
    }

    public void helloFromJava() {
        Log.e("TAG", "helloFromJava()");
    }

    public void printString(String s) {
        Log.e("TAG","C中输入的：" + s);
    }

    public static void sayHello(String s){
        Log.e("TAG",  "我是java代码中的JNI."
                + "java中的sayHello(String s)静态方法，我被C调用了:"+ s);
    }
}
