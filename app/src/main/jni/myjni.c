//
// Created by 62527 on 2017/10/26.
//

#include "myjni.h"
#include <jni.h>
#include <string.h>
#include <malloc.h>
char* _JString2CStr(JNIEnv* env, jstring jstr) {
    char* rtn = NULL;
    jclass clsstring = (*env)->FindClass(env, "java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env,"GB2312");
    jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid, strencode); // String .getByte("GB2312");
    jsize alen = (*env)->GetArrayLength(env, barr);
    jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    if(alen > 0) {
        rtn = (char*)malloc(alen+1); //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen]=0;
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba,0);
    return rtn;
}
JNIEXPORT jstring JNICALL
Java_com_example_yaphet_myjavajni_JNI_hello(JNIEnv *env, jobject instance, jstring s_) {
    char * fromjava= _JString2CStr(env,s_);
    char * fromc="I am from c";
    strcat(fromjava,fromc);
    //jstring     (*NewStringUTF)(JNIEnv*, const char*);
    return (*env)->NewStringUTF(env,fromjava);
}

JNIEXPORT jint JNICALL
Java_com_example_yaphet_myjavajni_JNI_add(JNIEnv *env, jobject instance, jint x, jint y) {
    // TODO
    return x+y;
}

JNIEXPORT jint JNICALL
Java_com_example_yaphet_myjavajni_JNI_checkPwd(JNIEnv *env, jobject instance, jstring pwd_) {
    char * pass = _JString2CStr(env,pwd_);
    char * password="123456";
    //int strcmp(const char* _Nonnull, const char* _Nonnull) __attribute_pure__;
    int result=strcmp(pass,password);
    // TODO
   if(result==0){
    return 200;
} else{
    return 400;
}
}

JNIEXPORT void JNICALL
Java_com_example_yaphet_myjavajni_JNI_callbackHelloFromJava(JNIEnv *env, jobject instance) {
    //获取类
    //jclass      (*FindClass)(JNIEnv*, const char*);
    jclass jclass1= (*env)->FindClass(env,"com/example/yaphet/myjavajni/JNI");
    //获取方法
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    jmethodID jmethodID1=(*env)->GetMethodID(env,jclass1,"helloFromJava","()V");
    //创建实例
    //jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject jobject1=(*env)->AllocObject(env,jclass1);
    //调用方法
    //void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    (*env)->CallVoidMethod(env,jobject1,jmethodID1);
    // TODO

}

JNIEXPORT void JNICALL
Java_com_example_yaphet_myjavajni_JNI_callbackAdd(JNIEnv *env, jobject instance) {
    jclass jclass1= (*env)->FindClass(env,"com/example/yaphet/myjavajni/JNI");
    //获取方法
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    jmethodID jmethodID1=(*env)->GetMethodID(env,jclass1,"addd","(II)I");
    //创建实例
    //jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject jobject1=(*env)->AllocObject(env,jclass1);
    //调用方法
    //void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    //jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
    (*env)->CallIntMethod(env,jobject1,jmethodID1,99,1);//在JNI类中调用的是由返回值的方法
    // TODO

}

JNIEXPORT void JNICALL
Java_com_example_yaphet_myjavajni_JNI_callbackPrintString(JNIEnv *env, jobject instance) {
    jclass jclass1= (*env)->FindClass(env,"com/example/yaphet/myjavajni/JNI");
    //获取方法
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    jmethodID jmethodID1=(*env)->GetMethodID(env,jclass1,"printString","(Ljava/lang/String;)V");
    //创建实例
    //jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject jobject1=(*env)->AllocObject(env,jclass1);
    //调用方法
    //void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    //jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
    //jstring     (*NewStringUTF)(JNIEnv*, const char*);
    char * string="I got it";
    jstring jstring1=(*env)->NewStringUTF(env,string);
    (*env)->CallVoidMethod(env,jobject1,jmethodID1,jstring1);
    // TODO

}

JNIEXPORT void JNICALL
Java_com_example_yaphet_myjavajni_JNI_callbackSayHello(JNIEnv *env, jobject instance) {
    jclass jclass1= (*env)->FindClass(env,"com/example/yaphet/myjavajni/JNI");
    //获取方法
    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    jmethodID jmethodID1=(*env)->GetStaticMethodID(env,jclass1,"sayHello","(Ljava/lang/String;)V");
    //创建实例
    //jobject     (*AllocObject)(JNIEnv*, jclass);
    //jobject jobject1=(*env)->AllocObject(env,jclass1);
    //调用方法
    //void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    //jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
    //(*env)->CallIntMethod(env,jobject1,jmethodID1,99,1);//在JNI类中调用的是由返回值的方法
    //void        (*CallStaticVoidMethod)(JNIEnv*, jclass, jmethodID, ...);
    char * string="I got it again";
    jstring jstring1=(*env)->NewStringUTF(env,string);
    (*env)->CallStaticVoidMethod(env,jclass1,jmethodID1,jstring1);
    // TODO

}