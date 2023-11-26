// generated from
// rosidl_typesupport_introspection_c/resource/rosidl_typesupport_introspection_c__visibility_control.h.in
// generated code does not contain a copyright notice

#ifndef CMD_DYNAMIXEL_QT__MSG__ROSIDL_TYPESUPPORT_INTROSPECTION_C__VISIBILITY_CONTROL_H_
#define CMD_DYNAMIXEL_QT__MSG__ROSIDL_TYPESUPPORT_INTROSPECTION_C__VISIBILITY_CONTROL_H_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cmd_dynamixel_qt __attribute__ ((dllexport))
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_IMPORT_cmd_dynamixel_qt __attribute__ ((dllimport))
  #else
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cmd_dynamixel_qt __declspec(dllexport)
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_IMPORT_cmd_dynamixel_qt __declspec(dllimport)
  #endif
  #ifdef ROSIDL_TYPESUPPORT_INTROSPECTION_C_BUILDING_DLL_cmd_dynamixel_qt
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_PUBLIC_cmd_dynamixel_qt ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cmd_dynamixel_qt
  #else
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_PUBLIC_cmd_dynamixel_qt ROSIDL_TYPESUPPORT_INTROSPECTION_C_IMPORT_cmd_dynamixel_qt
  #endif
#else
  #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_cmd_dynamixel_qt __attribute__ ((visibility("default")))
  #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_IMPORT_cmd_dynamixel_qt
  #if __GNUC__ >= 4
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_PUBLIC_cmd_dynamixel_qt __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_TYPESUPPORT_INTROSPECTION_C_PUBLIC_cmd_dynamixel_qt
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // CMD_DYNAMIXEL_QT__MSG__ROSIDL_TYPESUPPORT_INTROSPECTION_C__VISIBILITY_CONTROL_H_
