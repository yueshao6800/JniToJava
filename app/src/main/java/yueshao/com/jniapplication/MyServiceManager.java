package yueshao.com.jniapplication;

import android.util.Log;

/**
 * @author lyg-hhy1
 * @date on 2019/3/28
 * @email yueshao6800@163.com
 * @describe
 */
public  class MyServiceManager {


    private  CallBack mCallBack;
    public void Call(byte[] bytes) {
        if (bytes != null)
            Log.e("MyServiceManager", bytes.toString());
        else {
            Log.e("MyServiceManager", "傻逼了");
        }
        if(mCallBack != null){
            mCallBack.call(bytes);
        }
    }


    public void setCallBack(CallBack callBack) {
        mCallBack = callBack;
    }


    private static class Holder{
        public  static MyServiceManager method = new MyServiceManager();
    }

    public static MyServiceManager imp(){
        return MyServiceManager.Holder.method;
    }
}
