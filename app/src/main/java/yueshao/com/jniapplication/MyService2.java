package yueshao.com.jniapplication;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.util.Log;

public class MyService2 extends Service {
    public MyService2() {
    }

    @Override
    public IBinder onBind(Intent intent) {
        // TODO: Return the communication channel to the service.
        throw new UnsupportedOperationException("Not yet implemented");
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        Log.e("MyService2","Thread.currentThread() ="+Thread.currentThread().getId());
//        MyServiceManager.imp().setCallBack(new CallBack<byte[]>(){
//            @Override
//            public void call (byte[] bytes){
//                if (bytes != null) {
//                    Log.e("MyService2", "收到数据=" + bytes.length);
//                } else {
//
//                    Log.e("MyService2", "收到数据=" + null);
//                }
//            }
//        });
        return START_STICKY;
    }

    @Override
    public void onCreate() {
        super.onCreate();

    }

    @Override
    public void onDestroy() {
        super.onDestroy();
    }

}
