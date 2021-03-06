package com.xiaowei.ndkcpp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private NDKCppInterface ndkCppInterface;
    private NDKCInterface ndkcInterface;
    private NDKCppSecondInterface ndkCppSecondInterface;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ndkCppInterface = new NDKCppInterface();
        ndkcInterface = new NDKCInterface();
        ndkCppSecondInterface = new NDKCppSecondInterface();
    }

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public void clickCppConst(View view) {
        ndkCppInterface.executeCppConst();
    }

    public void clickCConst(View view) {
        ndkcInterface.executeCConst();
    }

    public void clickCPPointer(View view) {
        ndkCppInterface.executeCppPointer();
    }

    public void clickCPPConstRef(View view) {
        ndkCppInterface.executeCppConstRef();
    }

    public void clickCPPInlineFunc(View view) {
        ndkCppInterface.executeCppInlineFunc();
    }

    public void clickCPPFuncParam(View view) {
        ndkCppInterface.executeCppFuncParam();
    }

    public void clickCPPFuncPointer(View view) {
        ndkCppInterface.executeCppFuncPointer();
    }

    public void clickCPPClass(View view) {
        ndkCppInterface.executeCppClass();
    }

    public void clickCPPConstruct(View view) {
        ndkCppSecondInterface.executeCppConstruct();
    }

    public void clickCPPDistruct(View view) {
        ndkCppSecondInterface.executeCppDestrcut();
    }

    public void clickCPPCopyFunc(View view) {
//        ndkCppSecondInterface.executeCppCopyFunc();
        ndkCppSecondInterface.executeCppCopyFuncScene();
    }

    public void clickCPPCopy(View view) {
        ndkCppSecondInterface.executeCppCopy();
    }
}
