package yueshao.com.jniapplication;

/**
 * @date on 2019/3/29
 * @author  lyg-hhy1
 * @email  yueshao6800@163.com
 * @describe
 */
public interface CallBack<T> {
    /**
     * 回调
     * @param t
     */
    void call(T t);
}
