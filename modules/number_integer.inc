<?php
// This line is so VIM recognizes this as a PHP file:
// vim:ft=php:shiftwidth=3:tabstop=3:

function csv2cck_field_options_number_integer_form( $form, &$form_state ) {
}


/* Return: array( 
 *    'safe_value', A printable version of the field.
 *    'raw_value', The value to store when creating the node with this field.
 */
function csv2cck_field_options_number_integer_convert(
   $data, $field_info, $options
) {
   if( empty( $data ) || is_numeric( $data ) ) {
      return array(
         'safe_value' => intval( $data ),
         'raw_value' => intval( $data ),
         'valid' => true,
      );
   } else {
      return array( 'safe_value' => '', 'raw_value' => '', 'valid' => false );
   }
}

function csv2cck_field_options_number_integer_attachment(
   $data_array, $field_info
) {
   // Build the branchy array that hangs off of $node->field[language][0].
   if( !empty( $data_array['raw_value'] ) ) {
      return array( 'value' => $data_array['raw_value'] );
   } else {
      return array();
   }
}

