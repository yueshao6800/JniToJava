package yueshao.com.jniapplication;

import android.util.Log;

/**
 * @author lyg-hhy1
 * @date on 2019/3/28
 * @email yueshao6800@163.com
 * @describe
 */
public  class  CallBackJni {

    public void Call(byte[] bytes) {
        Log.e("CallBackJni","Thread.currentThread() ="+Thread.currentThread().getId());
        if (bytes != null)
            Log.e("CallBackJni", bytes.toString());
        else {
            Log.e("CallBackJni", "傻逼了");
        }
        MyServiceManager.imp().Call(bytes);
    }



}
