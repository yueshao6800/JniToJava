#include <jni.h>
#include <string>
#include <pthread.h>
//#include <NativeMethod.h>

extern "C"


JNIEXPORT jstring JNICALL Java_yueshao_com_jniapplication_NativeMethod_getAesKey
        (JNIEnv *env, jobject thiz){
    std::string key = "01234567890123456789012345678901";
    return env->NewStringUTF(key.c_str());
}



//JavaVM *g_VM;
//jobject g_obj;
//JNIEXPORT void JNICALL Java_xxx_nativeDownload(JNIEnv *env, jobject thiz) {
//
//    //JavaVM是虚拟机在JNI中的表示，等下再其他线程回调java层需要用到
//    (*env)->GetJavaVM(env, &g_VM);
//    // 生成一个全局引用保留下来，以便回调
//    g_obj = (*env)->NewGlobalRef(env, thiz);
//
//    // 此处使用c语言开启一个线程，进行回调，这时候java层就不会阻塞，只是在等待回调
//    pthread_create(xxx,xxx, download,NULL);
//    return ;
//}
//
//
////在此处跑在子线程中，并回调到java层
//void download(void *p) {
//    JNIEnv *env;
//
//    //获取当前native线程是否有没有被附加到jvm环境中
//    int getEnvStat = (*g_VM)->GetEnv(g_VM, (void **) &env,JNI_VERSION_1_6);
//    if (getEnvStat == JNI_EDETACHED) {
//        //如果没有， 主动附加到jvm环境中，获取到env
//        if ((*g_VM)->AttachCurrentThread(g_VM, &env, NULL) != 0) {
//            return;
//        }
//        mNeedDetach = JNI_TRUE;
//    }
//
//    //通过全局变量g_obj 获取到要回调的类
//    jclass javaClass = (*env)->GetObjectClass(env, g_obj);
//
//    if (javaClass == 0) {
//        LOG("Unable to find class");
//        (*g_VM)->DetachCurrentThread(g_VM);
//        return;
//    }
//
//    //获取要回调的方法ID
//    jmethodID javaCallbackId = (*env)->GetMethodID(env, jSdkClass,
//                                                   "onProgressCallBack", "(JJ)I");
//    if (javaCallbackId == NULL) {
//        LOGD("Unable to find method:onProgressCallBack");
//        return;
//    }
//    //执行回调
//    (*env)->CallIntMethod(env, g_obj, javaCallbackId,1,1);
//
//    //释放当前线程
//    if(mNeedDetach) {
//        (*g_VM)->DetachCurrentThread(g_VM);
//    }
//    env = NULL;
//}

//extern "C"
//JNIEXPORT void JNICALL
//Java_yueshao_com_jniapplication_Main2Activity_CallBack(JNIEnv *env, jobject instance,
//                                                       jobject callBack) {
//
//    // TODO
//
//    //找到需要调用的方法ID
//    jmethodID javaCallback = (*env)->GetMethodID(env, callBack,
//                                                 "onProgressCallBack", "(JJ)I");
//
//    //这时候要回调还没有jobject，那就new 一个
//    jmethodID sdkInit = (*env)->GetMethodID(env, jSdkClass,"<init>","()V");
//    jobject jSdkObject = (*env)->NewObject(env,jSdkClass,sdkInit);
//
//    //进行回调，ret是java层的返回值（这个有些场景很好用）
//    jint ret = (*env)->CallIntMethod(env, jSdkObject, javaCallback,1,1);
//
//    return ;
//
//}


extern "C"

JNIEXPORT void JNICALL Java_yueshao_com_jniapplication_NativeMethod_CallBack
        (JNIEnv *env, jobject obj,  jbyteArray data){

    jclass jCallBack = env->FindClass("yueshao/com/jniapplication/CallBackJni");

    jmethodID constructor = env->GetMethodID(jCallBack, "<init>", "()V");

    jobject jSdkClass = env->NewObject(jCallBack, constructor);


//    jclass jCallBack = env->GetObjectClass(callBackJni);


    //找到需要调用的方法ID
    jmethodID javaCallback = env->GetMethodID(jCallBack,
                                                 "Call", "([B)V");

//    //这时候要回调还没有jobject，那就new 一个
//    jmethodID sdkInit = env->GetMethodID(jSdkClass,"<init>","()V");
//    jobject jSdkObject = env->NewObject(env,jSdkClass,sdkInit);

    //进行回调，ret是java层的返回值（这个有些场景很好用）
//    jbyte *jbyte1 = new jbyte[1024];
//    for (int i = 0; i < 1024; ++i) {
//        jbyte1[i] = 1;
//    }

//    jbyte gs_raw_data[256];
//    int i;
//    jbyte* bytedata = env->GetByteArrayElements(data, 0);
//    memset(&gs_raw_data,0,255);
//    memcpy(&gs_raw_data,bytedata,len);
// parse the data
//below is the return 's bytearray lens
//    jbyteArray jarrRV =env->NewByteArray(da);

//    std::string key = "01234567890123456789012345678901";
//    jstring result = env->NewStringUTF(key.c_str());
    env->CallVoidMethod(jSdkClass, javaCallback,data);
//    return ;
}
