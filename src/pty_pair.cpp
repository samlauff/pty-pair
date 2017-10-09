#include "./pty_pair.h"

/*extern "C" {
  void init(v8::Handle<v8::Object> target) {
    Nan::HandleScope scope;
    Nan::SetMethod(target, "createPair", Set);
  }
}

NODE_MODULE(ptypair, init)*/


void EIO_Open(uv_work_t* req) {
	OpenBaton* data = static_cast<OpenBaton*>(req->data);

  // int flags = (O_RDWR | O_NOCTTY | O_NONBLOCK | O_CLOEXEC | O_SYNC);
  // int fd = open(data->path, flags);

  // if (-1 == fd) {
  //   snprintf(data->errorString, sizeof(data->errorString), "Error: %s, cannot open %s", strerror(errno), data->path);
  //   return;
  // }

  // if (-1 == setup(fd, data)) {
  //   close(fd);
  //   return;
  // }

	int console_master_1, console_slave_1, console_master_2, console_slave_2;
	// pthread_t console_thread_1, console_thread_2;
	char slave_port_name_1[256], slave_port_name_2[256];


  	openpty(&console_master_1, &console_slave_1, slave_port_name_1, NULL, NULL);
	openpty(&console_master_2, &console_slave_2, slave_port_name_2, NULL, NULL);

  	data->result = 3;
}


NAN_METHOD(Hello) {
    // 'info' is a macro's "implicit" parameter - it's a bridge object between C++ and JavaScript runtimes
    // You would use info to both extract the parameters passed to a function as well as set the return value.
    v8::Local<v8::Array> arr = Nan::New<v8::Array>(2);
    Nan::Set(arr, 0, Nan::New("port1").ToLocalChecked());
	Nan::Set(arr, 1, Nan::New("port2").ToLocalChecked());
    info.GetReturnValue().Set(arr);

	// OpenBaton* baton = new OpenBaton();
	// memset(baton, 0, sizeof(OpenBaton));
	// uv_work_t* req = new uv_work_t();
	// req->data = baton;
	// uv_queue_work(uv_default_loop(), req, EIO_Open, NULL);
	int console_master_1, console_slave_1, console_master_2, console_slave_2;
	// pthread_t console_thread_1, console_thread_2;
	char slave_port_name_1[256], slave_port_name_2[256];


  	openpty(&console_master_1, &console_slave_1, slave_port_name_1, NULL, NULL);
	openpty(&console_master_2, &console_slave_2, slave_port_name_2, NULL, NULL);

  	// data->result = 3;
}

// Module initialization logic
NAN_MODULE_INIT(Initialize) {
    // Export the `Hello` function (equivalent to `export function Hello (...)` in JS)
    NAN_EXPORT(target, Hello);
}

// extern "C" {
//   void init(v8::Handle<v8::Object> target) {
//     Nan::HandleScope scope;
//     Nan::SetMethod(target, "hello", Hello);
//   }
// }

// Create the module called "addon" and initialize it with `Initialize` function (created with NAN_MODULE_INIT macro)
NODE_MODULE(addon, Initialize)