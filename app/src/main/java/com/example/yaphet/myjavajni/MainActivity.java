package com.example.yaphet.myjavajni;

import android.app.Activity;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {
    private Button bt_main_hello;
    private Button bt_main_add;
    private Button bt_main_key;
    private Button bt_main_helloback;
    private Button bt_main_addback;
    private Button bt_main_stringgback;
    private Button bt_main_staticback;
    private JNI jni;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        bt_main_hello = (Button) findViewById(R.id.bt_main_hello);
        bt_main_add = (Button) findViewById(R.id.bt_main_add);
        bt_main_key = (Button) findViewById(R.id.bt_main_key);
        bt_main_helloback = (Button)findViewById(R.id.bt_main_helloback);
        bt_main_addback = (Button)findViewById(R.id.bt_main_addback);
        bt_main_stringgback = (Button)findViewById(R.id.bt_main_stringgback);
        bt_main_staticback = (Button)findViewById(R.id.bt_main_staticback);
        bt_main_staticback.setOnClickListener(new Mylitenerr());
        bt_main_stringgback.setOnClickListener(new Mylitenerr());
        bt_main_addback.setOnClickListener(new Mylitenerr());
        bt_main_hello.setOnClickListener(new Mylitenerr());
        bt_main_add.setOnClickListener(new Mylitenerr());
        bt_main_key.setOnClickListener(new Mylitenerr());
        bt_main_helloback.setOnClickListener(new Mylitenerr());
        jni=new JNI();
    }
    class Mylitenerr implements View.OnClickListener {

        @Override
        public void onClick(View v) {
        switch (v.getId()) {
            case R.id.bt_main_hello :
                String hello = jni.hello("I am from java");
                Toast.makeText(MainActivity.this, "bt_main_hello"+hello, Toast.LENGTH_SHORT).show();
                break;
            case R.id.bt_main_add :
                int add = jni.add(22, 33);
                Toast.makeText(MainActivity.this, "bt_main_add---"+add, Toast.LENGTH_SHORT).show();

                break;
            case R.id.bt_main_key :
                int result = jni.checkPwd("123456");
                Toast.makeText(MainActivity.this, "bt_main_key----"+result, Toast.LENGTH_SHORT).show();

                break;
            case R.id.bt_main_helloback :
                jni.callbackHelloFromJava();
                //注意在方法在java方法mainactivity中时相当于用反射的的机制new出一个mainactivity，那么mainactivity就没有生命周期，只是一个普通的类。没有.this方法
                Toast.makeText(MainActivity.this, "bt_main_key----", Toast.LENGTH_SHORT).show();

                break;
            case R.id.bt_main_addback :
                jni.callbackAdd();

                break;
            case R.id.bt_main_stringgback :
                jni.callbackPrintString();

                break;
            case R.id.bt_main_staticback :
                jni.callbackSayHello();

                break;
            }
        }
    }
}
