package yueshao.com.jniapplication;

/**
 * @author yueshao
 * @package yueshao.com.jniapplication
 * @date 2019/3/28 7:13 PM
 * @describe TODO
 * @email yueshao6800@163.com
 */
public class NativeMethod {
    public native String getAesKey();
    public native void CallBack(byte[] bytes);


    static  {
        System.loadLibrary("native-lib");
    }

    private static class Holder{
        public  static NativeMethod method = new NativeMethod();
    }

    public static NativeMethod imp(){
        return Holder.method;
    }
}
