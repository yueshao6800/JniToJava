package yueshao.com.jniapplication;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;

public class Main2Activity extends AppCompatActivity {

    private Button buttonPanel;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        Log.e(Main2Activity.class.getName(), NativeMethod.imp().getAesKey());
        buttonPanel = findViewById(R.id.buttonPanel);


        buttonPanel.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {


                startService(new Intent(Main2Activity.this,MyService.class));
            }
        });
        startService(new Intent(this,MyService.class));
//        startService(new Intent(this,MyService2.class));


        MyServiceManager.imp().setCallBack(new CallBack<byte[]>(){
            @Override
            public void call (byte[] bytes){
                if (bytes != null) {
                    Log.e("MyService2", "收到数据=" + bytes.length);
                } else {

                    Log.e("MyService2", "收到数据=" + null);
                }
            }
        });
    }


}
